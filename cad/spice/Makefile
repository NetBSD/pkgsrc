# $NetBSD: Makefile,v 1.6 1998/08/20 15:16:41 tsarna Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/08 09:21:37 tg Exp
#

DISTNAME=	sp3f4.kit
PKGNAME=	spice-3f5
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Spice3/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-cad.eecs.berkeley.edu/Software/software.html

# documentation in ftp://ic.eecs.berkeley.edu/pub/Spice3/um.3f3.ps

#		These are included as patch-ab
#PATCH_SITES=	ftp://ilpsoft.eecs.berkeley.edu/pub/SPICE3F5/
#PATCHFILES=	grid.patch newcoms.patch spsmp.patch

USE_X11=	yes
NO_WRKSUBDIR=	yes

do-configure:
	${RM} -f ${WRKSRC}/makefile
	${SED} 's@$${X11BASE}@${X11BASE}@' <${FILESDIR}/NetBSD \
		>${WRKSRC}/conf/NetBSD
	${MV} ${WRKSRC}/conf/defaults ${WRKSRC}/conf/defaults.BAK
	${SED} \
		-e 's@$${X11BASE}@${X11BASE}@' \
		-e 's@$${PREFIX}@${PREFIX}@' \
		<${WRKSRC}/conf/defaults.BAK >${WRKSRC}/conf/defaults

do-build:
	cd ${WRKSRC} ; util/build NetBSD default

do-install:
	cd ${WRKSRC} ; util/build NetBSD install
	chmod a+rx ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg \
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help	\
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	strip ${PREFIX}/bin/spice3 ${PREFIX}/bin/nutmeg	\
	  ${PREFIX}/bin/sconvert ${PREFIX}/bin/help \
	  ${PREFIX}/bin/proc2mod ${PREFIX}/bin/multidec
	chmod -R a+rX ${PREFIX}/share/spice3
	${INSTALL_MAN} ${WRKSRC}/man/man5/mfbcap.5 ${PREFIX}/man/man5/mfbcap.5
	${INSTALL_MAN} ${WRKSRC}/man/man1/sconvert.1 ${PREFIX}/man/man1/sconvert.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/nutmeg.1 ${PREFIX}/man/man1/nutmeg.1
	${INSTALL_MAN} ${WRKSRC}/man/man1/spice.1 ${PREFIX}/man/man1/spice.1
	${INSTALL_MAN} ${WRKSRC}/man/man3/mfb.3 ${PREFIX}/man/man3/mfb.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/spice3
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${PREFIX}/share/examples/spice3
.endif

.include "../../mk/bsd.pkg.mk"

x:
.if exists(${PACKAGES})
	ls -lad ${PACKAGES}
.endif
