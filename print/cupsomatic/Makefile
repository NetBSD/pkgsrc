# $NetBSD: Makefile,v 1.7 2001/05/15 18:10:03 jlam Exp $

DISTNAME=	cupsomatic
PKGNAME=	${DISTNAME}-1.6
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
HOMEPAGE=	http://www.linuxprinting.org/cups-doc.html
COMMENT=	Foomatic CUPS printer filter

CONFLICTS+=	cupsomatic-200012??

DIST_SUBDIR=	${PKGNAME}

DEPENDS+=	cups>=1.1.1:../../print/cups
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	mpage-[0-9]*:../../print/mpage

USE_PERL5=	# defined
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}

FILTERDIR=	${PREFIX}/libexec/cups/filter

post-extract:
	cd ${WRKSRC}; ${MV} ${DISTNAME} ${DISTNAME}.in

do-build:
	${SED}	-e "s,@PERL@,${PERL5},g"				\
		-e "s,@LOCALBASE@,${LOCALBASE},g"			\
		${WRKSRC}/${DISTNAME}.in > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${FILTERDIR}

.include "../../mk/bsd.pkg.mk"
