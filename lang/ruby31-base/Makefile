# $NetBSD: Makefile,v 1.6 2022/07/18 12:48:38 jperkin Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION}
PKGREVISION=	3
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby ${RUBY_VERSION} release minimum base package

RUBY_VERSIONS_ACCEPTED=	31

MAKE_JOBS_SAFE=		no
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax yacc pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		test
CONFIGURE_ARGS+=	--enable-shared --enable-install-static-library
MAKE_ENV+=		XDG_DATA_HOME=${WRKDIR}
WRKSRC=			${RUBY_WRKSRC}
FILES_SUBST+=		PKGMANDIR=${PKGMANDIR:Q}

.include "options.mk"
.include "../../lang/ruby/platform.mk"

.if !empty(RUBY_SUFFIX)
CONFIGURE_ARGS+=	--program-suffix=${RUBY_SUFFIX}
CONFIGURE_ARGS+=	--with-soname=${RUBY_NAME}
CONFIGURE_ARGS+=	--with-ruby-version=${RUBY_VER_DIR}
CONFIGURE_ARGS+=	--with-ruby-pc="ruby-${RUBY_VERSION}.pc"
.endif

CONFIGURE_ENV+=		ac_cv_path_MJIT_CC=${CC}
CONFIGURE_ENV.Darwin+=	ac_cv_prog_dsymutil=

DOCS=		BSDL CONTRIBUTING.md COPYING COPYING.ja ChangeLog GPL \
		KNOWNBUGS.rb LEGAL NEWS.md README.ja.md README.md \
		README.EXT README.EXT.ja
EXT_DOCS=	syslog/syslog.txt

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
OPENSSL_EXAMPLES=	c_rehash.rb cert2text.rb certstore.rb cipher.rb \
			crlstore.rb echo_cli.rb echo_svr.rb gen_csr.rb \
			smime_read.rb smime_write.rb wget.rb

REPLACE_RUBY=		\
	libexec/bundle libexec/bundler libexec/erb libexec/irb \
	libexec/racc libexec/rdoc libexec/ri \
	.bundle/gems/debug-${RUBY_DEBUG_VER}/exe/rdbg \
	.bundle/gems/rake-${RUBY_RAKE_VER}/exe/rake \
	.bundle/gems/rbs-${RUBY_RBS_VER}/exe/rbs \
	.bundle/gems/typeprof-${RUBY_TYPEPROF_VER}/exe/typeprof
REPLACE_RUBY_DIRS=	ext lib sample
INSTALLATION_DIRS+=	bin libexec ${PKGMANDIR}/man1 \
			${RUBY_DOC}/csv/arguments \
			${RUBY_DOC}/csv/options/common \
			${RUBY_DOC}/csv/options/generating \
			${RUBY_DOC}/csv/options/parsing \
			${RUBY_DOC}/csv/recipes \
			${RUBY_DOC}/images ${RUBY_DOC}/irb ${RUBY_DOC}/pty \
			${RUBY_DOC}/ripper \
			${RUBY_DOC}/stringio ${RUBY_DOC}/syntax \
			${RUBY_EG}/bigdecimal ${RUBY_EG}/pty
# ${RUBY_ARCHINC} ${RUBY_ARCHLIB}
EMPTY_DIRS=		generator/template markup/simple_markup

NOT_PAX_MPROTECT_SAFE+=	bin/${RUBY_NAME}

pre-configure:
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${TOUCH} ${WRKSRC}/prelude.c
	${CHMOD} -x ${WRKSRC}/sample/test.rb

pre-install:
#	cd ${WRKSRC}/lib; \
#		${FIND} . \( -name '*.orig' -o -name '*.orig_dist' \) \
#		-exec ${RM} -f {} \;
.for f in ${EMPTY_DIRS}
	${RMDIR} ${WRKSRC}/lib/rdoc/${f} 2>/dev/null || ${TRUE}
.endfor

post-install:
	cd ${DESTDIR}${PREFIX}/${GEM_HOME} && \
		find . \! -type d \( -name 'Makefile*' -o -name '.*.time' \
			-o -name '*.o' -o -name 'gem_make.out' \) -exec rm {} \;
	cd ${WRKSRC}/doc && ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_DOC}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}
.endfor
.for f in ${EXT_DOCS}
	${INSTALL_DATA} ${WRKSRC}/ext/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}
.endfor
	cd ${WRKSRC}/ext/ripper; ${PAX} -rw README ${DESTDIR}${PREFIX}/${RUBY_DOC}/ripper
	cd ${WRKSRC}/ext/stringio; ${PAX} -rw README.md ${DESTDIR}${PREFIX}/${RUBY_DOC}/stringio
	cd ${WRKSRC}/sample; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}
.for f in ${BIGDECIMAL_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/ext/bigdecimal/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/bigdecimal
.endfor
.for f in ${OPENSSL_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/openssl/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/openssl
.endfor
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/${GEM_HOME}/gems
	${RUBY_GENERATE_PLIST}

.include "../../mk/bdb.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libyaml/buildlink3.mk"
.include "../../lang/ruby/Makefile.common"
.include "../../mk/bsd.pkg.mk"
