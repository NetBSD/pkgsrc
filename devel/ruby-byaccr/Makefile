# $NetBSD: Makefile,v 1.6 2005/02/19 05:27:35 taca Exp $
# FreeBSD: ports/devel/ruby-byaccr/Makefile,v 1.2 2000/11/03 15:49:06 knu Exp

DISTNAME=	byaccr-0.1
PKGNAME=	ruby-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'
EXAMPLES=	Makefile cal.y calfunc.rb main.rb

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/byaccr
.endfor

.include "../../mk/bsd.pkg.mk"
