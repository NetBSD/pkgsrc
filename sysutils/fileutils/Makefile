# $NetBSD: Makefile,v 1.14 2001/12/19 00:14:31 seb Exp $

DISTNAME=		fileutils-4.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GNU:=fileutils/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=		GNU file management utilities

USE_GTEXINFO=		yes
NO_PATCH=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-prefix=g

post-configure:
	@${TOUCH} ${WRKSRC}/m4/Makefile.am ${WRKSRC}/m4/Makefile.in \
		${WRKSRC}/m4/Makefile

.include "../../mk/bsd.pkg.mk"
