# $NetBSD: Makefile,v 1.31 2005/02/21 15:35:53 taca Exp $
# FreeBSD: ports/lang/ruby/Makefile,v 1.40 2001/01/18 19:53:38 knu Exp

DISTNAME=	ruby-${RUBY_VERSION}
PKGREVISION=	1
CATEGORIES=	lang ruby
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby, object-oriented interpreted programming language

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_WRAPPER=	yes
PLIST_SRC=	${WRKDIR}/PLIST

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+= 	${RUBY_PKGPREFIX}>=${RUBY_VERSION}:../${RUBY_PKGPREFIX}

RUBY_COMMANDS=	irb ruby
.if ${RUBY_VER} >= 18
RUBY_COMMANDS+=	erb h2rb rdoc ri testrb
.endif

do-install:
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if ${RUBY_NAME} != "ruby"
.for file in ${RUBY_COMMANDS}
	${LN} -sf ${file}${RUBY_VER} ${LOCALBASE}/bin/${file}
	${ECHO} bin/${file} >> ${PLIST_SRC}
.endfor
	${LN} -sf ${RUBY_NAME}.1 ${PREFIX}/man/man1/ruby.1
	${ECHO} man/man1/ruby.1 >> ${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
