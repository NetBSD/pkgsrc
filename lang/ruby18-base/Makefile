# $NetBSD: Makefile,v 1.45.4.2 2008/09/17 10:41:37 tron Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION_SUFFIX}
PKGREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
#PKGREVISION=

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby 1.8 based release minimum package

RUBY_VERSION=	${RUBY18_VERSION}

CONFLICTS=	${RUBY_PKGPREFIX}-dbm-[0-9]* \
		${RUBY_PKGPREFIX}-digest-[0-9]* \
		${RUBY_PKGPREFIX}-iconv-[0-9]* \
		${RUBY_PKGPREFIX}-openssl-[0-9]* \
		${RUBY_PKGPREFIX}-tcltk-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS+=	pax yacc
GNU_CONFIGURE=	yes
TEST_TARGET=	test
CONFIGURE_ARGS+= --enable-shared \
		--with-ssl-include="${BUILDLINK_PREFIX.openssl}/include" \
		--with-ssl-lib="${BUILDLINK_PREFIX.openssl}/lib"
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
WRKSRC=		${RUBY_WRKSRC}

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS.SunOS+=	-B static -lsunmath -B dynamic -lm
LDFLAGS.SunOS+=	-L${SUNWSPROBASE}/lib -Wl,-R${SUNWSPROBASE}/lib
CONFIGURE_ENV+=	LDSHARED="${CC} -G"
.else
LIBS.SunOS+=	-lm
.endif

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

MAKE_DIRS+=	${RUBY_SITERIDIR}
FILES_SUBST+=	DATE=${DATE:Q}

.include "options.mk"

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix=${RUBY_SUFFIX:Q}
.endif

#
# IRIX work around which should be fixed.
#
PLIST_VARS+=	io
.if ${OPSYS} != "IRIX"
PLIST.io=	yes
.endif

#
# Work around for getucontext(3)
#
.if ${OPSYS} == "DragonFly" && ${OS_VERSION} == "1.8.0"
CONFIGURE_ENV+=	ac_cv_header_ucontext_h=no
.endif

#
# work around for getaddrinfo(3)
#
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-wide-getaddrinfo
.endif

DOCS=		COPYING COPYING.ja ChangeLog NEWS README \
		README.EXT README.EXT.ja README.ja ToDo \
		doc/ChangeLog-1.8.0 doc/NEWS-1.8.0 \
		doc/forwardable.rd doc/forwardable.rd.ja \
		doc/irb/irb-tools.rd.ja doc/irb/irb.rd doc/irb/irb.rd.ja \
		doc/shell.rd doc/shell.rd.ja
EXT_DOCS=	bigdecimal/bigdecimal_en.html bigdecimal/bigdecimal_ja.html \
		dl/doc/dl.txt etc/etc.txt etc/etc.txt.ja syslog/syslog.txt \
		zlib/doc/zlib.rd

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
DL_EXAMPLES=		c++sample.C c++sample.rb drives.rb getch.rb libc.rb \
			msgbox.rb msgbox2.rb stream.rb
OPENSSL_EXAMPLES=	c_rehash.rb cert2text.rb cert_store_view.rb \
			certstore.rb cipher.rb crlstore.rb echo_cli.rb \
			echo_svr.rb gen_csr.rb smime_read.rb smime_write.rb \
			wget.rb
PTY_EXAMPLES=		expect_sample.rb script.rb shl.rb

REPLACE_RUBY_DIRS=	bin ext lib sample
INSTALLATION_DIRS=	bin ${RUBY_ARCHLIB} ${RUBY_DOC}/irb ${RUBY_DOC}/pty \
			${RUBY_EG}/bigdecimal ${RUBY_EG}/dl \
			${RUBY_EG}/openssl ${RUBY_EG}/pty
FIX_PERM=		${RUBY_ARCHLIB}/digest.h ${RUBY_ARCHLIB}/dl.h \
			${RUBY_ARCHLIB}/dlconfig.h

pre-configure:
	${RM} -f ${WRKSRC}/ext/curses/extconf.rb
	${RM} -f ${WRKSRC}/ext/gdbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${RM} -f ${WRKSRC}/ext/tk/extconf.rb

pre-install:
	cd ${WRKSRC}; ${FIND} . \( -name '*.orig' -o -name '*.orig_dist' \) \
		-exec ${RM} -f {} \;

post-install:
	${INSTALL_DATA} ${FILESDIR}/CHANGES.pkgsrc ${DESTDIR}${PREFIX}/${RUBY_DOC}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/${f:C/^doc\///}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/ext/dl/h2rb ${DESTDIR}${PREFIX}/bin/h2rb${RUBY_VER}
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}
.endfor
	cd ${WRKSRC}/ext/pty; ${PAX} -rw README.* ${DESTDIR}${PREFIX}/${RUBY_DOC}/pty
	cd ${WRKSRC}/sample; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}
.for f in ${BIGDECIMAL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/bigdecimal/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/bigdecimal
.endfor
.for f in ${DL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/dl/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/dl
.endfor
.for f in ${OPENSSL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/openssl/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/openssl
.endfor
.for f in ${PTY_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/pty/${f} ${DESTDIR}${PREFIX}/${RUBY_EG}/pty
.endfor
.for f in ${FIX_PERM}
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/${f}
.endfor
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
