# $NetBSD: Makefile,v 1.32 2012/09/11 20:32:14 asau Exp $

DISTNAME=	RasMol_2.7.3
PKGNAME=	rasmol-2.7.3
PKGREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://www.bernstein-plus-sons.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bernstein-plus-sons.com/software/rasmol/
COMMENT=	Molecular Graphics Visualisation Tool

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	YES
USE_TOOLS+=	gunzip mkdirhier

MAKE_ENV+=	DEPTHDEF=${DEPTHDEF:Q}

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

.if defined(RASMOL_DEPTH)
.  if ${RASMOL_DEPTH} == 32
DEPTHDEF=	-DTHIRTYTWOBIT
.  elif ${RASMOL_DEPTH} == 16
DEPTHDEF=	-DSIXTEENBIT
.  endif
.endif
DEPTHDEF?=	-DEIGHTBIT

pre-configure:
	${LN} -sf ${WRKDIR}/${DISTNAME}/doc  ${WRKSRC}
	${LN} -sf ${WRKDIR}/${DISTNAME}/data ${WRKSRC}
	cd ${WRKSRC} && ${SED} "s#@@PREFIX@@#${PREFIX}#" rasmol.h > \
		rasmol.h.new && ${MV} rasmol.h.new rasmol.h

post-extract:
	cd ${WRKSRC} && ${RM} -rf RCS doc/RCS src/RCS src/msc/RCS

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NOTICE ${DESTDIR}${PREFIX}/share/doc/rasmol
	for doc in manualA4.pdf.gz manualA4.ps.gz manualA4.rtf.gz	\
			manualUS.pdf.gz manualUS.ps.gz manualUS.rtf.gz	\
			refcardA4.pdf.gz refcardA4.ps.gz		\
			refcardA4.rtf.gz refcardUS.pdf.gz		\
			refcardUS.ps.gz refcardUS.rtf.gz; do		\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/$$doc		\
			${DESTDIR}${PREFIX}/share/doc/rasmol;		\
	done
	for data in 1crn.pdb 1gpd.pdb.gz 1ldb.pdb.gz 1ldm.pdb.gz	\
			3cro.pdb 4hir.ent.gz 4ins.CIF 7lyz.pdb		\
			IUCR9800028.cif asprin.alc pdb2mcg.ent; do	\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/data/$$data	\
			${DESTDIR}${PREFIX}/share/examples/rasmol;	\
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
