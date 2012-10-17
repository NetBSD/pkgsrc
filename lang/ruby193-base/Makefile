# $NetBSD: Makefile,v 1.17.2.2 2012/10/17 09:47:20 tron Exp $
#

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION_FULL}
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby ${RUBY_VERSION} release minimum base package
LICENSE=	${RUBY_LICENSE}

RUBY_VERSION_SUPPORTED=	193

MAKE_JOBS_SAFE=		no
USE_LANGUAGES=		c
USE_TOOLS+=		pax yacc
GNU_CONFIGURE=		yes
TEST_TARGET=		test
CONFIGURE_ARGS+=	--enable-shared
WRKSRC=			${RUBY_WRKSRC}

MAKE_DIRS=		${RUBY_SITEARCHLIB} ${RUBY_VENDORARCHLIB}

#
# Don't refrect pkgsrc's INSTALL macro since Ruby expect it could
# execute by unprivileged user.
#
CONFIGURE_ENV+=		INSTALL="${INSTALL} ${COPY}" \
			INSTALL_DATA= INSTALL_PROGRAM= INSTALL_SCRIPT=

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS.SunOS+=	-B static -lsunmath -B dynamic -lm
LDFLAGS.SunOS+=	-L${SUNWSPROBASE}/lib -Wl,-R${SUNWSPROBASE}/lib
CONFIGURE_ENV+=	LDSHARED="${CC} -G"
.else
LIBS.SunOS+=	-lm
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=	OBJCOPY=:
CONFIGURE_ENV+=	ac_cv_prog_PKG_CONFIG=""
.endif

.if ${OPSYS} == "MirBSD"
# if present, an unsupported sysconf call is used
CONFIGURE_ENV+=	ac_cv_func_getgrnam_r=no
.endif

# Ruby build process depends on config.status's content
CONFIG_STATUS_OVERRIDE=	# empty

MAKE_DIRS+=	${RUBY_SITERIDIR}
FILES_SUBST+=	DATE=${DATE:Q}

REQD_DIRS+=	${GEM_HOME}/cache
REQD_DIRS+=	${GEM_HOME}/doc

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	lib/rubygems/config_file.rb
SUBST_SED.conf=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

.include "options.mk"

.include "../../lang/ruby/rubyversion.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+= --program-suffix=${RUBY_SUFFIX}
CONFIGURE_ARGS+= --with-soname=${RUBY_NAME}
CONFIGURE_ARGS+= --with-sitedir=${PREFIX}/${RUBY_SITELIB_BASE}
CONFIGURE_ARGS+= --with-vendordir=${PREFIX}/${RUBY_VENDORLIB_BASE}
CONFIGURE_ARGS+= --with-ruby-version=${RUBY_VERSION}
CONFIGURE_ARGS+= --with-ruby-pc="ruby-${RUBY_VERSION}.pc"
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
# work around for Linux
#
.if ${OPSYS} == "Linux"
CONFIGURE_ENV+=	MKDIR_P=${MKDIR:Q}
.endif

DOCS=		COPYING COPYING.ja ChangeLog NEWS README \
		README.EXT README.EXT.ja README.ja ToDo \
		doc/ChangeLog-1.8.0 doc/ChangeLog-YARV doc/NEWS-1.8.7 \
		doc/forwardable.rd doc/forwardable.rd.ja \
		doc/irb/irb-tools.rd.ja doc/irb/irb.rd doc/irb/irb.rd.ja \
		doc/shell.rd doc/shell.rd.ja
EXT_DOCS=	bigdecimal/bigdecimal_en.html bigdecimal/bigdecimal_ja.html \
		syslog/syslog.txt

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
OPENSSL_EXAMPLES=	c_rehash.rb cert2text.rb certstore.rb cipher.rb \
			crlstore.rb echo_cli.rb echo_svr.rb gen_csr.rb \
			smime_read.rb smime_write.rb wget.rb

REPLACE_RUBY=		bin/erb bin/gem bin/irb bin/rake bin/rdoc \
			bin/ri bin/testrb
REPLACE_RUBY_DIRS=	ext lib sample
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 \
			${RUBY_DOC}/irb ${RUBY_DOC}/ripper ${RUBY_DOC}/stringio \
			${RUBY_EG}/bigdecimal ${RUBY_EG}/pty
# ${RUBY_ARCHINC} ${RUBY_ARCHLIB}
EMPTY_DIRS=		generator/template markup/simple_markup

pre-configure:
	${RM} -f ${WRKSRC}/ext/curses/extconf.rb
	${RM} -f ${WRKSRC}/ext/gdbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/fiddle/extconf.rb
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${RM} -f ${WRKSRC}/ext/tk/extconf.rb

pre-install:
	cd ${WRKSRC}/bin; for f in *; do ${LN} -f $$f $${f}${RUBY_VER}; done
	cd ${WRKSRC}/lib; \
		${FIND} . \( -name '*.orig' -o -name '*.orig_dist' \) \
		-exec ${RM} -f {} \;
.for f in ${EMPTY_DIRS}
	${RMDIR} ${WRKSRC}/lib/rdoc/${f} 2>/dev/null || ${TRUE}
.endfor

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/${f:C/^doc\///}
.endfor
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}
.endfor
	cd ${WRKSRC}/ext/ripper; ${PAX} -rw README ${DESTDIR}${PREFIX}/${RUBY_DOC}/ripper
	cd ${WRKSRC}/ext/stringio; ${PAX} -rw README ${DESTDIR}${PREFIX}/${RUBY_DOC}/stringio
	cd ${WRKSRC}/sample; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}
.for f in ${BIGDECIMAL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/ext/bigdecimal/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/bigdecimal
.endfor
.for f in ${OPENSSL_EXAMPLES}
	${INSTALL_DATA} ${RUBY_WRKSRC}/sample/openssl/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/openssl
.endfor
	${RUBY_GENERATE_PLIST}

.include "../../mk/bdb.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
