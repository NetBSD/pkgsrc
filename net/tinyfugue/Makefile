#	$NetBSD: Makefile,v 1.2 1998/04/26 05:57:40 mrg Exp $

# New ports collection makefile for:	tinyfugue
# Version required:	4.0a6
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# from: Id: Makefile,v 1.8 1998/04/11 04:21:19 jseger Exp
#

DISTNAME=	tf-40a6
PKGNAME=	tf-4.0a6
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	packages@NetBSD.ORG

MAN=		tf.1
MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include <bsd.pkg.mk>
