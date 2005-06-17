# $NetBSD: Makefile,v 1.18 2005/06/17 03:50:30 jlam Exp $

DISTNAME=	cupsomatic
PKGNAME=	${DISTNAME}-2.2
PKGREVISION=	2
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

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://www.linuxprinting.org/cups-doc.html
COMMENT=	Foomatic CUPS printer filter

CONFLICTS+=	cupsomatic-200012??

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

DEPENDS+=	cups>=1.1.14nb1:../../print/cups
DEPENDS+=	foomatic-gswrapper>=1.2:../../print/foomatic-gswrapper
DEPENDS+=	mpage-[0-9]*:../../print/mpage

USE_PERL5=	yes
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}/${DISTNAME}

FILTERDIR=	${PREFIX}/libexec/cups/filter

do-build:
	cd ${WRKSRC};							\
	for file in cupsomatic; do					\
		${SED}	-e "s|/usr/bin/perl|${PERL5}|g"			\
			-e "s|/usr/local|${LOCALBASE}|g"		\
			-e "s|/etc/foomatic|${PKG_SYSCONFDIR}/foomatic|g" \
			$${file} > $${file}.fixed;			\
		${MV} $${file}.fixed $${file};				\
	done

do-install:
	${INSTALL_DATA_DIR} ${FILTERDIR}
	cd ${WRKSRC};							\
	for file in cupsomatic; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${file} ${FILTERDIR};	\
	done

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
