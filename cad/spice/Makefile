# $NetBSD: Makefile,v 1.16 2000/11/14 14:30:14 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/08 09:21:37 tg Exp
#

DISTNAME=	sp3f4.kit
PKGNAME=	spice-3f5.1
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://bwrc.eecs.berkeley.edu/Classes/IcBook/SPICE/

DEPENDS+=	readline>=4.0:../../devel/readline

# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

#		These are included as patch-ae
#PATCH_SITES=	ftp://ilpsoft.eecs.berkeley.edu/pub/SPICE3F5/
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch

USE_X11=	yes
NO_WRKSUBDIR=	yes

CONFLICTS=	ng-spice-*

do-configure:
	${RM} -f ${WRKSRC}/makefile
	${SED} 's;@WRKSRC@;${WRKSRC};g' <${FILESDIR}/NetBSD \
		>${WRKSRC}/conf/NetBSD
	${MV} ${WRKSRC}/conf/defaults ${WRKSRC}/conf/defaults.BAK
	${SED} \
		-e 's@$${X11BASE}@${X11PREFIX}@' \
		-e 's@$${PREFIX}@${PREFIX}@' \
		<${WRKSRC}/conf/defaults.BAK >${WRKSRC}/conf/defaults

do-build:
	cd ${WRKSRC} ; util/build NetBSD default

do-install:
	cd ${WRKSRC} ; util/build NetBSD install
	${CHMOD} a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help	\
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg	\
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help \
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	${CHMOD} -R a+rX ${PREFIX}/share/spice3
	${INSTALL_MAN} ${WRKSRC}/man/man5/mfbcap.5 ${PREFIX}/man/man5/mfbcap.5
	${INSTALL_MAN} ${WRKSRC}/man/man1/sconvert.1 ${PREFIX}/man/man1/sconvert.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/nutmeg.1 ${PREFIX}/man/man1/nutmeg.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/spice.1 ${PREFIX}/man/man1/spice.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/mfb.3 ${PREFIX}/man/man3/mfb.3

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/spice3
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${PREFIX}/share/examples/spice3

.include "../../mk/bsd.pkg.mk"
