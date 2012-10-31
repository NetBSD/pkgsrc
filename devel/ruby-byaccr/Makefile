# $NetBSD: Makefile,v 1.13 2012/10/31 11:19:40 asau Exp $

DISTNAME=	byaccr-0.1
PKGNAME=	ruby-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'

EXAMPLES=	Makefile cal.y calfunc.rb main.rb

INSTALLATION_DIRS=	bin share/examples/byaccr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/byaccr ${DESTDIR}${PREFIX}/bin
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${DESTDIR}${PREFIX}/share/examples/byaccr
.endfor

.include "../../mk/bsd.pkg.mk"
