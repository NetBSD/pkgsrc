# $NetBSD: Makefile,v 1.1.1.1 2000/03/13 04:41:58 wiz Exp $

DISTNAME=	RasMol_2.7.1
PKGNAME=	rasmol-2.7.1
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.bernstein-plus-sons.com/software/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.bernstein-plus-sons.com/software/rasmol/

USE_IMAKE=	YES

MAKE_ENV+=	"DEPTHDEF=${DEPTHDEF}"

post-patch:
	${LN} -sf ${WRKDIR}/${DISTNAME}/doc  ${WRKSRC}
	${LN} -sf ${WRKDIR}/${DISTNAME}/data ${WRKSRC}
	${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}/doc/rasmol.1.gz
	cd ${WRKSRC} && ${SED} "s#@@PREFIX@@#${PREFIX}#" rasmol.h > \
		rasmol.h.new && ${MV} rasmol.h.new rasmol.h

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/NOTICE ${PREFIX}/share/doc/rasmol
.for DOC in	manualA4.pdf.gz manualA4.ps.gz manualA4.rtf.gz \
		manualUS.pdf.gz manualUS.ps.gz manualUS.rtf.gz \
		refcardA4.pdf.gz refcardA4.ps.gz refcardA4.rtf.gz \
		refcardUS.pdf.gz refcardUS.ps.gz refcardUS.rtf.gz
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${DOC} \
		${PREFIX}/share/doc/rasmol
.endfor
.for DATA in 	1crn.pdb 1gpd.pdb.gz 1ldb.pdb.gz 1ldm.pdb.gz 3cro.pdb \
		4hir.ent.gz 4ins.CIF 7lyz.pdb IUCR9800028.cif asprin.alc \
		pdb2mcg.ent
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/data/${DATA} \
		${PREFIX}/share/examples/rasmol
.endfor

.include "../../mk/bsd.pkg.mk"

# test must be below inclusion of bsd.pkg.mk
DEPTHDEF=	-DEIGHTBIT
.if defined(RASMOL_DEPTH)
.if ${RASMOL_DEPTH} == 32
DEPTHDEF=	-DTHIRTYTWOBIT
.else if ${RASMOL_DEPTH} == 16
DEPTHDEF=	-DSIXTEENBIT
.endif
.endif
