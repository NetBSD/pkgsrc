# $NetBSD: Makefile,v 1.3 2001/12/24 22:32:00 jlam Exp $

DISTNAME=	foomatic-gswrapper
PKGNAME=	${DISTNAME}-1.2
CATEGORIES=	print
EXTRACT_SUFX=	# empty

# Not sure why ${MASTER_SITE_LOCAL:=${PKGNAME}} doesn't work, but the
# following does the correct substitution.
#
.for subdir in ${PKGNAME}
MASTER_SITES=	${MASTER_SITE_LOCAL:=${subdir}/}
.endfor

# The definitive location of the distfile is at www.linuxprinting.org,
# but this file has no revision number.
#
#MASTER_SITES+=	http://www.linuxprinting.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.linuxprinting.org/gswrapper.html
COMMENT=	Foomatic Ghostscript Wrapper

DIST_SUBDIR=	${PKGNAME}

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
