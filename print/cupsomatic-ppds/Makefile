# $NetBSD: Makefile,v 1.1.1.1 2000/12/21 15:06:06 jlam Exp $

DISTNAME=	all-com-ppds
PKGNAME=	cupsomatic-ppds-20001220
WRKSRC=		${WRKDIR}/cupsomatic-ppd
CATEGORIES=	print

# Not sure why ${MASTER_SITE_LOCAL:=${PKGNAME}} doesn't work, but the
# following does the correct substitution.
#
.for subdir in ${PKGNAME}
MASTER_SITES=	${MASTER_SITE_LOCAL:=${subdir}/}
.endfor

# The definitive location of the distfile is at www.linuxprinting.org,
# but this file changes daily as more PPDs are added.  Rather than track
# this file very aggressively, we'll place a new copy at MASTER_SITE_LOCAL
# periodically and update this package accordingly.
#
#MASTER_SITES+=	http://www.linuxprinting.org/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.linuxprinting.org/cups-doc.html

CONFLICTS+=	cupsomatic-200012??

DIST_SUBDIR=	${PKGNAME}

DEPENDS+=	cups>=1.1.1:../../print/cups
DEPENDS+=	cupsomatic-[0-9]*:../../print/cupsomatic

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

PLIST_SRC=	${WRKDIR}/PLIST
MODELDIR=	share/cups/model

# Dynamically generate the PLIST during installation to ease package
# upgrading.
#
do-install:
	${RM} -f ${PLIST_SRC}
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	cd ${WRKSRC}/ppd; for dir in *; do (				\
	    cd $${dir}; for file in *.ppd; do				\
		${ECHO} "Installing ${PREFIX}/${MODELDIR}/$${dir}/$${file}"; \
		${INSTALL_DATA_DIR} ${PREFIX}/${MODELDIR}/$${dir};	\
		${INSTALL_DATA} $${file}				\
			${PREFIX}/${MODELDIR}/$${dir}/$${file};		\
		${ECHO} "${MODELDIR}/$${dir}/$${file}" >> ${PLIST_SRC};	\
	    done;							\
	    ${ECHO} "@dirrm ${MODELDIR}/$${dir}" >> ${PLIST_SRC} );	\
	done

.include "../../mk/bsd.pkg.mk"
