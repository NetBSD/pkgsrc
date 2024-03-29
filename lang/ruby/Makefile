# $NetBSD: Makefile,v 1.77 2024/01/21 08:36:58 taca Exp $

DISTNAME=	# empty
PKGNAME=	ruby-${RUBY_VERSION}
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://www.ruby-lang.org/en/
COMMENT=	Wrapper package for Ruby programming language

CONFLICTS=	pkg_alternatives-[0-9]*

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}

RUBY_COMMANDS=	bundle bundler erb gem irb racc rake rbs rdbg rdoc ri ruby typeprof
.if ${RUBY_VER} >= 32
RUBY_COMMANDS+=	syntax_suggest
.endif
.if ${OPSYS} == "Cygwin"
RUBY_COMMANDS+=	rubyw
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
CHECK_INTERPRETER_SKIP=	bin/* ${PKGMANDIR}/man1/ruby.1

.if ${RUBY_NAME} == "ruby"
GENERATE_PLIST+=	${ECHO} "@comment This plist intentionally left empty";
.else
.  for f in ${RUBY_COMMANDS}
GENERATE_PLIST+=	${ECHO} bin/${f};
.  endfor
GENERATE_PLIST+=	${ECHO} man/man1/ruby.1;
.endif

do-install:
.if ${RUBY_NAME} != "ruby"
.  for f in ${RUBY_COMMANDS}
	${LN} -sf ${f}${RUBY_SUFFIX} ${DESTDIR}${PREFIX}/bin/${f}
.  endfor
	${LN} -sf ${RUBY_NAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ruby.1
.endif

.include "../../mk/bsd.pkg.mk"
