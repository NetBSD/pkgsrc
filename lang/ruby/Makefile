# $NetBSD: Makefile,v 1.51 2012/09/16 15:24:18 taca Exp $

DISTNAME=	# empty
PKGNAME=	ruby-${RUBY_VERSION_FULL}
PKGREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Wrapper package for Ruby programming language

CONFLICTS=	pkg_alternatives-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION}:../../lang/${RUBY_PKGPREFIX}-base

RUBY_COMMANDS=	erb irb ruby testrb
.if ${RUBY_VER} == "18"
RUBY_COMMANDS+=	h2rb
.elif ${RUBY_VER} == "193"
RUBY_COMMANDS+=	gem rake
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
	${LN} -sf ${f}${RUBY_VER} ${DESTDIR}${PREFIX}/bin/${f}
.  endfor
	${LN} -sf ${RUBY_NAME}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ruby.1
.endif

.include "../../mk/bsd.pkg.mk"
