# $NetBSD: Makefile,v 1.8 2006/06/06 00:15:28 minskim Exp $

DISTNAME=	byaccr-0.1
PKGNAME=	ruby-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'

MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP} BINMODE=${BINMODE}
EXAMPLES=	Makefile cal.y calfunc.rb main.rb

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/byaccr
.endfor

.include "../../mk/bsd.pkg.mk"
