# $NetBSD: Makefile,v 1.1.1.1 2001/05/15 18:26:11 jlam Exp $

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

USE_PERL5=	# defined
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}

do-build:
	${MV} ${WRKSRC}/${DISTNAME} ${WRKSRC}/${DISTNAME}.orig
	${SED}	-e "s,/usr/bin/perl,${PERL5},g"				\
		${WRKSRC}/${DISTNAME}.orig > ${WRKSRC}/${DISTNAME}
	${RM} ${WRKSRC}/${DISTNAME}.orig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
