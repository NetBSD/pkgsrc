# $NetBSD: Makefile,v 1.3 2001/03/24 19:37:10 zuntum Exp $
#

DISTNAME=	loco-0.32
CATEGORIES=	misc
MASTER_SITES=	http://zjuul.net/~jules/loco/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://zjuul.net/~jules/loco/
COMMENT=	Colorize file or standard input and print on the standard output

USE_PERL5=	YES

ALL_TARGET=	# defined

post-patch:
	${SED} "s,/usr/bin/perl,${LOCALBASE}/bin/perl,g"		\
		${WRKSRC}/loco > ${WRKSRC}/loco.done
	${MV} ${WRKSRC}/loco.done ${WRKSRC}/loco

.include "../../mk/bsd.pkg.mk"
