# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:20 tsarna Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/11 04:21:19 jseger Exp
#

DISTNAME=	tf-40a6
PKGNAME=	tf-4.0a6
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://tf.tcp.com/~hawkeye/tf/

MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include "../../mk/bsd.pkg.mk"
