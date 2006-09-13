# $NetBSD: Makefile,v 1.10 2006/09/13 00:42:12 taca Exp $

DISTNAME=	byaccr-0.1
PKGNAME=	ruby-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'

EXAMPLES=	Makefile cal.y calfunc.rb main.rb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/byaccr ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/byaccr
.endfor

.include "../../mk/bsd.pkg.mk"
