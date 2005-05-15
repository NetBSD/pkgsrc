# $NetBSD: Makefile,v 1.20 2005/05/15 22:02:26 jlam Exp $

DISTNAME=	RasMol_2.7.1
PKGNAME=	rasmol-2.7.1
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.bernstein-plus-sons.com/software/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.bernstein-plus-sons.com/software/rasmol/
COMMENT=	Molecular Graphics Visualisation Tool

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_IMAKE=	YES
PKGSRC_USE_TOOLS+=	gunzip

MAKE_ENV+=	DEPTHDEF="${DEPTHDEF}"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

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
