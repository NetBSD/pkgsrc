# $NetBSD: Makefile,v 1.24 2020/04/17 11:05:44 ryoon Exp $
#

DISTNAME=	OmegaT_5.2.0_Beta_Without_JRE
PKGNAME=	${DISTNAME:S/OmegaT_/OmegaT-/:S/_Without_JRE//:S/_Beta//:S/_/./g}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omegat/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.omegat.org/
COMMENT=	The translation memory (TM) application written in Java
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
USE_JAVA=	yes
USE_JAVA2=	8

NO_BUILD=	yes

USE_TOOLS+=	pax

SUBST_CLASSES+=			fix-omegat
SUBST_STAGE.fix-omegat=		pre-configure
SUBST_MESSAGE.fix-omegat=	fixing pathes
SUBST_FILES.fix-omegat=		OmegaT
SUBST_SED.fix-omegat=		-e 's,@OMEGATDIR@,${PREFIX}/${OMEGATDIR},g'
SUBST_SED.fix-omegat+=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

REPLACE_SH=	OmegaT

OMEGATDIR=	share/OmegaT
OMEGATDOCDIR=	share/doc/OmegaT

INSTALLATION_DIRS=	bin \
			${OMEGATDIR} \
			${OMEGATDIR}/lib \
			${OMEGATDOCDIR} \
			${OMEGATDOCDIR}/images
pre-patch:
	${INSTALL_DATA} ${FILESDIR}/OmegaT.in ${WRKSRC}/OmegaT

do-install:
	${INSTALL_DATA} ${WRKSRC}/*txt \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*html \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/OmegaT.jar \
		${DESTDIR}${PREFIX}/${OMEGATDIR}
	cd ${WRKSRC}/docs && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	cd ${WRKSRC}/images && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/lib/*.txt \
		${DESTDIR}${PREFIX}/${OMEGATDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${DESTDIR}${PREFIX}/${OMEGATDIR}/lib
	${INSTALL_DATA} ${FILESDIR}/omegat.prefs \
		${DESTDIR}${PREFIX}/${OMEGATDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/OmegaT ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
