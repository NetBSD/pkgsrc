# $NetBSD: Makefile,v 1.5 2003/03/29 12:40:31 jmmv Exp $
#

DISTNAME=	CSSC-0.13alpha.pl1a
PKGNAME=	cssc-0.13a.1
WRKSRC=		${WRKDIR}/CSSC-0.13alpha.pl1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
INFO_FILES=		cssc.info
TEXINFO_REQD=		4.0
TEXINFO_OVERRIDE=	YES

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
