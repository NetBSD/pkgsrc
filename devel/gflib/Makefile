# $NetBSD: Makefile,v 1.6 2023/12/30 01:28:55 zafer Exp $
#

DISTNAME=	gflib
PKGNAME=	gflib-20030604
CATEGORIES=	devel
MASTER_SITES=	 https://web.eecs.utk.edu/~jplank/plank/gflib/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cs.utk.edu/~plank/plank/gdlib/
COMMENT=	Reed Solomon and Galois Field error correction library

MAKE_FILE=	makefile

BUILD_TARGET=	w16

INSTALLATION_DIRS=	bin

do-install:
	for f in gf_div gf_mult parity_test rs_decode_file		\
			rs_encode_file xor; do				\
		${INSTALL_PROGRAM} ${WRKSRC}/$$f			\
			${DESTDIR}${PREFIX}/bin/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
