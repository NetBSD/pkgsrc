# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 01:40:09 wiz Exp $
#

DISTNAME=	eawpats-full-10
PKGNAME=	eawpatches-10
CATEGORIES=	audio
MASTER_SITES=	http://www.stardate.bc.ca/eawpatches/
EXTRACT_SUFX=	.rar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.stardate.bc.ca/eawpatches/

BUILD_DEPENDS=  unrar:../../archivers/unrar

CONFLICTS=	guspatches-*

# setting NO_EXTRACT to yes instead make 'extract' fail because of a
# missing WRKDIR
EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	if [ ! -d ${PREFIX}/share/timidity ]; then \
		${MKDIR} ${PREFIX}/share/timidity; \
	fi
	cd ${PREFIX}/share/timidity && \
	unrar x -o+ -inul ${DISTDIR}/${DISTNAME}
	${SED}  -e "s@c:.timidity@${PREFIX}/share/timidity@" \
		-e "s@dir c:.eawpats@@" \
		< ${PREFIX}/share/timidity/timidity.cfg > /tmp/timidity.tmp
	${MV} /tmp/timidity.tmp ${PREFIX}/share/timidity/timidity.cfg

.include "../../mk/bsd.pkg.mk"
