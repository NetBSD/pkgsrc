# $NetBSD: Makefile,v 1.2 2001/03/16 20:53:03 zuntum Exp $
#

DISTNAME=	loco-0.32
CATEGORIES=	misc
MASTER_SITES=	http://zjuul.net/~jules/loco/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://zjuul.net/~jules/loco/
COMMENT=	Colorize file or standard input and print on the standard output

MAKE_ENV+=	"PREFIX=${PREFIX}"

USE_PERL5=	YES

ALL_TARGET=	# defined

post-patch:
	${SED} "s,/usr/bin/perl,${LOCALBASE}/bin/perl,g"		\
		${WRKSRC}/loco > ${WRKSRC}/loco.done
	${MV} ${WRKSRC}/loco.done ${WRKSRC}/loco

.include "../../mk/bsd.pkg.mk"
