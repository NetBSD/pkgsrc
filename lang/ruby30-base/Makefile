# $NetBSD: Makefile,v 1.8 2022/07/18 12:47:52 jperkin Exp $

DISTNAME=	${RUBY_DISTNAME}
PKGNAME=	${RUBY_PKGPREFIX}-base-${RUBY_VERSION}
PKGREVISION=	2
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	${RUBY_HOMEPAGE}
COMMENT=	Ruby ${RUBY_VERSION} release minimum base package

CONFLICTS+=	${RUBY_PKGPREFIX}-fiddle-[0-9]*

RUBY_VERSIONS_ACCEPTED=	30

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

CONFIGURE_ENV.Darwin+=	ac_cv_prog_dsymutil=

DOCS=		BSDL COPYING COPYING.ja ChangeLog LEGAL NEWS.md README.EXT \
		README.EXT.ja README.ja.md README.md doc/.document \
		doc/ChangeLog-0.06_to_0.52 doc/ChangeLog-0.50_to_0.60 \
		doc/ChangeLog-0.60_to_1.1 doc/ChangeLog-1.8.0 \
		doc/ChangeLog-1.9.3 doc/ChangeLog-2.0.0 doc/ChangeLog-2.1.0 \
		doc/ChangeLog-2.2.0 doc/ChangeLog-2.3.0 doc/ChangeLog-2.4.0 \
		doc/ChangeLog-YARV doc/NEWS-1.8.7 doc/NEWS-1.9.1 \
		doc/NEWS-1.9.2 doc/NEWS-1.9.3 doc/NEWS-2.0.0 doc/NEWS-2.1.0 \
		doc/NEWS-2.2.0 doc/NEWS-2.3.0 doc/NEWS-2.4.0 doc/NEWS-2.5.0 \
		doc/NEWS-2.6.0 doc/NEWS-2.7.0 doc/bug_triaging.rdoc \
		doc/contributing.rdoc doc/csv/arguments/io.rdoc \
		doc/csv/options/common/col_sep.rdoc \
		doc/csv/options/common/quote_char.rdoc \
		doc/csv/options/common/row_sep.rdoc \
		doc/csv/options/generating/force_quotes.rdoc \
		doc/csv/options/generating/quote_empty.rdoc \
		doc/csv/options/generating/write_converters.rdoc \
		doc/csv/options/generating/write_empty_value.rdoc \
		doc/csv/options/generating/write_headers.rdoc \
		doc/csv/options/generating/write_nil_value.rdoc \
		doc/csv/options/parsing/converters.rdoc \
		doc/csv/options/parsing/empty_value.rdoc \
		doc/csv/options/parsing/field_size_limit.rdoc \
		doc/csv/options/parsing/header_converters.rdoc \
		doc/csv/options/parsing/headers.rdoc \
		doc/csv/options/parsing/liberal_parsing.rdoc \
		doc/csv/options/parsing/nil_value.rdoc \
		doc/csv/options/parsing/return_headers.rdoc \
		doc/csv/options/parsing/skip_blanks.rdoc \
		doc/csv/options/parsing/skip_lines.rdoc \
		doc/csv/options/parsing/strip.rdoc \
		doc/csv/options/parsing/unconverted_fields.rdoc \
		doc/csv/recipes/filtering.rdoc \
		doc/csv/recipes/generating.rdoc doc/csv/recipes/parsing.rdoc \
		doc/csv/recipes/recipes.rdoc doc/dig_methods.rdoc \
		doc/dtrace_probes.rdoc doc/extension.ja.rdoc \
		doc/extension.rdoc doc/forwardable.rd.ja doc/globals.rdoc \
		doc/images/boottime-classes.png doc/implicit_conversion.rdoc \
		doc/irb/irb-tools.rd.ja doc/irb/irb.rd.ja doc/keywords.rdoc \
		doc/maintainers.rdoc doc/make_cheatsheet.md doc/marshal.rdoc \
		doc/method_documentation.rdoc doc/pty/README.expect.ja \
		doc/pty/README.ja doc/ractor.md doc/regexp.rdoc \
		doc/security.rdoc doc/signals.rdoc doc/standard_library.rdoc \
		doc/syntax/assignment.rdoc doc/syntax/calling_methods.rdoc \
		doc/syntax/comments.rdoc doc/syntax/control_expressions.rdoc \
		doc/syntax/exceptions.rdoc doc/syntax/literals.rdoc \
		doc/syntax/methods.rdoc doc/syntax/miscellaneous.rdoc \
		doc/syntax/modules_and_classes.rdoc \
		doc/syntax/pattern_matching.rdoc doc/syntax/precedence.rdoc \
		doc/syntax/refinements.rdoc doc/syntax.rdoc doc/yarvarch.en \
		doc/yarvarch.ja
EXT_DOCS=	syslog/syslog.txt

BIGDECIMAL_EXAMPLES=	linear.rb nlsolve.rb pi.rb
OPENSSL_EXAMPLES=	c_rehash.rb cert2text.rb certstore.rb cipher.rb \
			crlstore.rb echo_cli.rb echo_svr.rb gen_csr.rb \
			smime_read.rb smime_write.rb wget.rb

REPLACE_RUBY=		\
	libexec/bundle libexec/bundler libexec/erb libexec/irb \
	libexec/racc libexec/rdoc libexec/ri \
	.bundle/gems/power_assert-${RUBY_POWER_ASSERT_VER}/bin/console \
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/bundle \
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/console \
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/rake \
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/rdoc \
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/rubocop \
	.bundle/gems/rake-${RUBY_RAKE_VER}/exe/rake \
	.bundle/gems/rbs-${RUBY_RBS_VER}/exe/rbs \
	.bundle/gems/typeprof-${RUBY_TYPEPROF_VER}/exe/typeprof
REPLACE_SH=		\
	.bundle/gems/rake-${RUBY_RAKE_VER}/bin/setup
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
	${RM} -f ${WRKSRC}/ext/gdbm/extconf.rb
	${RM} -f ${WRKSRC}/ext/readline/extconf.rb
	${TOUCH} ${WRKSRC}/prelude.c
	${CHMOD} -x ${WRKSRC}/sample/test.rb

pre-install:
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
