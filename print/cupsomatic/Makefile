# $NetBSD: Makefile,v 1.1.1.1 2000/12/08 16:57:23 jlam Exp $

DISTNAME=	all-com-ppds
PKGNAME=	cupsomatic-20001208
CATEGORIES=	print
MASTER_SITES=	http://www.linuxprinting.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.linuxprinting.org/cups-doc.html

DEPENDS+=	cups>=1.1.1:../../print/cups
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	mpage-[0-9]*:../../print/mpage

WRKSRC=		${WRKDIR}/cupsomatic-ppd

USE_PERL5=	# defined
NO_CONFIGURE=	# defined

FILTERDIR=	${PREFIX}/libexec/cups/filter
MODELDIR=	${PREFIX}/share/cups/model

post-extract:
	cd ${WRKSRC}; ${MV} cupsomatic cupsomatic.in

do-build:
	${SED}	-e "s,@PERL@,${PERL5},g" \
		-e "s,@LOCALBASE@,${LOCALBASE},g" \
		< ${WRKSRC}/cupsomatic.in > ${WRKSRC}/cupsomatic

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cupsomatic ${FILTERDIR}
	cd ${WRKSRC}/ppd; for dir in *; do \
		( cd $${dir}; for file in *.ppd; do \
			${INSTALL_DATA} $${file} ${MODELDIR}/$${dir}-$${file}; \
		  done ); \
	done

.include "../../mk/bsd.pkg.mk"
