# $NetBSD: Makefile,v 1.9 2003/07/17 22:52:26 grant Exp $

DISTNAME=	foomatic-gswrapper
PKGNAME=	foomatic-gswrapper-1.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	print
EXTRACT_SUFX=	# empty
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}

# The definitive location of the distfile is at www.linuxprinting.org,
# but this file has no revision number.
#
#MASTER_SITES+=	http://www.linuxprinting.org/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/gswrapper.html
COMMENT=	Foomatic Ghostscript Wrapper

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_BUILDLINK2=		YES
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}

REPLACE_PERL=	${DISTNAME}

do-build:	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
