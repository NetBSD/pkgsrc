# $NetBSD: Makefile,v 1.7 2001/05/16 15:39:10 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/11 04:21:19 jseger Exp
#

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	packages@NetBSD.ORG
HOMEPAGE=	http://tf.tcp.com/~hawkeye/tf/
COMMENT=	Popular programmable MUD client, with macro support and more

MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include "../../mk/bsd.pkg.mk"
