# $NetBSD: Makefile,v 1.5 2001/05/08 15:54:48 agc Exp $

DISTNAME=	cupsomatic
PKGNAME=	cupsomatic-1.3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/${DIST_SUBDIR}/
EXTRACT_SUFX=	# empty

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
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/cupsomatic

FILTERDIR=	${PREFIX}/libexec/cups/filter

post-extract:
	cd ${WRKSRC}; ${MV} cupsomatic cupsomatic.in

do-build:
	${SED}	-e "s,@PERL@,${PERL5},g" \
		-e "s,@LOCALBASE@,${LOCALBASE},g" \
		< ${WRKSRC}/cupsomatic.in > ${WRKSRC}/cupsomatic

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cupsomatic ${FILTERDIR}

.include "../../mk/bsd.pkg.mk"
