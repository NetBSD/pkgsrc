# $NetBSD: Makefile,v 1.26.2.3 2006/12/09 10:17:47 salo Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION_SUFFIX}
#PKGREVISION=
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	ruby-1.8.5-base-${RUBY18_PATCH_DATE}.patch.bz2
PATCH_DIST_STRIP= -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby 1.8 based release minimum package

RUBY_VERSION=	${RUBY18_VERSION}

CONFLICTS=	${RUBY_PKGPREFIX}-dbm-[0-9]* \
		${RUBY_PKGPREFIX}-digest-[0-9]* \
		${RUBY_PKGPREFIX}-iconv-[0-9]* \
		${RUBY_PKGPREFIX}-openssl-[0-9]* \
		${RUBY_PKGPREFIX}-tcltk-[0-9]*

USE_LANGUAGES=	c
USE_TOOLS+=	yacc
GNU_CONFIGURE=	yes
TEST_TARGET=	test
CONFIGURE_ARGS+= --enable-shared \
		--with-ssl-include="${BUILDLINK_PREFIX.openssl}/include" \
		--with-ssl-lib="${BUILDLINK_PREFIX.openssl}/lib"
CONFIGURE_ENV+=		PREFIX=${PREFIX:Q}
WRKSRC=			${RUBY_WRKSRC}

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

MAKE_DIRS+=	${RUBY_SITERIDIR}

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix=${RUBY_SUFFIX:Q}
.endif

.include "options.mk"

FILES_SUBST+=	DATE=${DATE:Q}

#
# IRIX work around which should be fixed.
#
.if ${OPSYS} == "IRIX"
PLIST_SUBST+=	HAS_IO="@comment "
.else
PLIST_SUBST+=	HAS_IO=
.endif

#
# work around for getaddrinfo(3)
#
.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-wide-getaddrinfo
.endif

DOCS=		COPYING COPYING.ja ChangeLog README \
		README.EXT README.EXT.ja README.ja ToDo \
		doc/ChangeLog-1.8.0 doc/NEWS \
		doc/forwardable.rd doc/forwardable.rd.ja \
		doc/shell.rd doc/shell.rd.ja doc/irb/irb-tools.rd.ja \
		doc/irb/irb.rd doc/irb/irb.rd.ja
EXT_DOCS=	bigdecimal/bigdecimal_en.html bigdecimal/bigdecimal_ja.html \
		dl/doc/dl.txt enumerator/enumerator.txt \
		etc/etc.txt etc/etc.txt.ja syslog/syslog.txt \
		zlib/doc/zlib.rd

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
DL_EXAMPLES=		c++sample.C c++sample.rb drives.rb getch.rb libc.rb \
			msgbox.rb msgbox2.rb stream.rb
OPENSSL_EXAMPLES=	c_rehash.rb cert2text.rb cert_store_view.rb \
			certstore.rb cipher.rb crlstore.rb echo_cli.rb \
			echo_svr.rb gen_csr.rb smime_read.rb smime_write.rb \
			wget.rb
PTY_EXAMPLES=		expect_sample.rb script.rb shl.rb

REPLACE_RUBY_DIRS=	${WRKSRC}/bin ${WRKSRC}/ext ${WRKSRC}/lib \
			${WRKSRC}/sample

pre-configure:
	${RM} -f ${WRKSRC}/ext/curses/extconf.rb
	${RM} -f ${WRKSRC}/ext/gdbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${RM} -f ${WRKSRC}/ext/tk/extconf.rb

pre-install:
	cd ${WRKSRC}; ${FIND} . \( -name '*.orig' -o -name '*.orig_dist' \) \
		-exec ${RM} -f {} \;

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/irb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/pty
	${INSTALL_DATA} ${FILESDIR}/CHANGES.pkgsrc ${RUBY_DOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${f:C/^doc\///}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/ext/dl/h2rb ${PREFIX}/bin/h2rb${RUBY_VER}
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${RUBY_DOCDIR}
.endfor
	${CP} -r ${WRKSRC}/ext/pty/README.* ${RUBY_DOCDIR}/pty
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/pty
	${CP} -r ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/bigdecimal
.for f in ${BIGDECIMAL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/bigdecimal/sample/${f} \
		${RUBY_EXAMPLESDIR}/bigdecimal
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/dl
.for f in ${DL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/dl/sample/${f} \
		${RUBY_EXAMPLESDIR}/dl
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/openssl
.for f in ${OPENSSL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/openssl/${f} \
		${RUBY_EXAMPLESDIR}/openssl
.endfor
.for f in ${PTY_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/pty/${f} ${RUBY_EXAMPLESDIR}/pty
.endfor
	${RUBY_GENERATE_PLIST}

.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
