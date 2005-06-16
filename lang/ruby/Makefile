# $NetBSD: Makefile,v 1.35 2005/06/16 06:58:01 jlam Exp $

DISTNAME=	ruby-${RUBY_VERSION}
PKGREVISION=	2
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Wrapper package for Ruby programming language

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_WRAPPER=	yes
PLIST_SRC=	${WRKDIR}/PLIST

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+= ${RUBY_PKGPREFIX}-base>=${RUBY_VERSION}:../${RUBY_PKGPREFIX}-base

RUBY_COMMANDS=	irb ruby
.if ${RUBY_VER} >= 18
RUBY_COMMANDS+=	erb h2rb rdoc ri testrb
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if ${RUBY_NAME} != "ruby"
.for f in ${RUBY_COMMANDS}
	${LN} -sf ${f}${RUBY_VER} ${LOCALBASE}/bin/${f}
	${ECHO} bin/${f} >> ${PLIST_SRC}
.endfor
	${LN} -sf ${RUBY_NAME}.1 ${PREFIX}/man/man1/ruby.1
	${ECHO} man/man1/ruby.1 >> ${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
