# $NetBSD: Makefile,v 1.3 2002/02/18 10:25:04 jmc Exp $
#

DISTNAME=	CSSC-0.13alpha.pl1a
PKGNAME=	cssc-0.13a.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

BUILD_DEPENDS+=		gtexinfo=>4.0:../../devel/gtexinfo

WRKSRC=	${WRKDIR}/CSSC-0.13alpha.pl1
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary

PATH= ${LOCALBASE}/bin:$$PATH

.include "../../mk/bsd.pkg.mk"
