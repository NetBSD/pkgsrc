# $NetBSD: Makefile,v 1.5 2002/04/20 14:41:05 cjep Exp $

DISTNAME=	RasMol_2.7.1
PKGNAME=	rasmol-2.7.1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.bernstein-plus-sons.com/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bernstein-plus-sons.com/software/rasmol/
COMMENT=	Molecular Graphics Visualisation Tool

USE_IMAKE=	YES

MAKE_ENV+=	DEPTHDEF="${DEPTHDEF}"

.if (${MACHINE_ARCH} == arm32)
. include "../../lang/gcc/Makefile.gcc"
MAKE_FLAGS+=	CC=${CC}
.endif

.include "../../mk/bsd.prefs.mk"

.if defined(RASMOL_DEPTH)
.if ${RASMOL_DEPTH} == 32
DEPTHDEF=	-DTHIRTYTWOBIT
.else if ${RASMOL_DEPTH} == 16
DEPTHDEF=	-DSIXTEENBIT
.endif
.endif
DEPTHDEF?=	-DEIGHTBIT


post-patch:
	${LN} -sf ${WRKDIR}/${DISTNAME}/doc  ${WRKSRC}
	${LN} -sf ${WRKDIR}/${DISTNAME}/data ${WRKSRC}
	${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}/doc/rasmol.1.gz
	cd ${WRKSRC} && ${SED} "s#@@PREFIX@@#${PREFIX}#" rasmol.h > \
		rasmol.h.new && ${MV} rasmol.h.new rasmol.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NOTICE ${PREFIX}/share/doc/rasmol
	for doc in manualA4.pdf.gz manualA4.ps.gz manualA4.rtf.gz	\
			manualUS.pdf.gz manualUS.ps.gz manualUS.rtf.gz	\
			refcardA4.pdf.gz refcardA4.ps.gz		\
			refcardA4.rtf.gz refcardUS.pdf.gz		\
			refcardUS.ps.gz refcardUS.rtf.gz; do		\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/$$doc		\
			${PREFIX}/share/doc/rasmol;			\
	done
	for data in 1crn.pdb 1gpd.pdb.gz 1ldb.pdb.gz 1ldm.pdb.gz	\
			3cro.pdb 4hir.ent.gz 4ins.CIF 7lyz.pdb		\
			IUCR9800028.cif asprin.alc pdb2mcg.ent; do	\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/data/$$data	\
			${PREFIX}/share/examples/rasmol;		\
	done

.include "../../mk/bsd.pkg.mk"
