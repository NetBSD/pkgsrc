# $NetBSD: Makefile,v 1.4 1998/08/20 15:17:05 tsarna Exp $

DISTNAME=	hugs-January1998-source
PKGNAME=	hugs-1.4
CATEGORIES=	lang
MASTER_SITES=	ftp://haskell.org/pub/haskell/hugs/January1998/ \
		ftp://ftp.cs.nott.ac.uk/pub/haskell/hugs/January1998/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nathanw@mit.edu
HOMEPAGE=	http://haskell.systemsz.cs.yale.edu/hugs/

WRKSRC=		${WRKDIR}/hugs/src
GNU_CONFIGURE=	yes
ALL_TARGET=	default
MAKE_ENV=	INSTALL="${INSTALL}" INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

post-extract:
	@${LN} -s ${FILESDIR}/configure ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
