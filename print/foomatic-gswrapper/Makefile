# $NetBSD: Makefile,v 1.5 2002/03/17 16:02:34 fredb Exp $

DISTNAME=	foomatic-gswrapper
PKGNAME=	foomatic-gswrapper-1.2
PKGREVISION=	1
CATEGORIES=	print
EXTRACT_SUFX=	# empty
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}

# The definitive location of the distfile is at www.linuxprinting.org,
# but this file has no revision number.
#
#MASTER_SITES+=	http://www.linuxprinting.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.linuxprinting.org/gswrapper.html
COMMENT=	Foomatic Ghostscript Wrapper

DIST_SUBDIR=	${PKGNAME_NOREV}

DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript

USE_BUILDLINK_ONLY=	YES
WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}

REPLACE_PERL=	${DISTNAME}

do-build:	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
