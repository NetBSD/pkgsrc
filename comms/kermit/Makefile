# New ports collection makefile for:	kermit
# Version required:     6.0.192
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $NetBSD: Makefile,v 1.6 1998/03/20 22:04:08 frueauf Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/11/26 23:16:51 jseger Exp
#

DISTNAME=	cku192src
PKGNAME=        kermit-6.0.192
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.th-darmstadt.de/pub/networking/kermit/

MAINTAINER=	packages@netbsd.org

RESTRICTED=	"'No redistribution' copyright"
MIRROR_DISTFILE= no
NO_WRKSUBDIR=	yes

# Do not list MAN/CAT pages here. It will confuse if MANZ is set.
# The pkg uses BSD-style-Makefiles itself, so it does the right thing.

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	${INSTALL_DATA} ${FILESDIR}/dot.kermrc ${PREFIX}/share/examples/kermit
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
