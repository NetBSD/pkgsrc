# $NetBSD: Makefile,v 1.17 2015/11/25 12:50:00 jperkin Exp $
#

DISTNAME=	OmegaT_3.5_01_Beta_Source
PKGNAME=	${DISTNAME:S/OmegaT_/OmegaT-/:S/_Source//:S/_Beta//:S/_/./g}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omegat/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.omegat.org/
COMMENT=	The translation memory (TM) application written in Java
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_JAVA=	yes
USE_JAVA2=	yes

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

USE_TOOLS+=	pax

SUBST_CLASSES+=			fix-omegat
SUBST_STAGE.fix-omegat=		pre-configure
SUBST_MESSAGE.fix-omegat=	fixing pathes
SUBST_FILES.fix-omegat=		OmegaT
SUBST_SED.fix-omegat=		-e 's,@OMEGATDIR@,${PREFIX}/${OMEGATDIR}/,g'
SUBST_SED.fix-omegat+=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME}/,g'

OMEGATDIR=	share/OmegaT
OMEGATDOCDIR=	share/doc/OmegaT

INSTALLATION_DIRS=	bin \
			${OMEGATDIR} \
			${OMEGATDIR}/lib \
			${OMEGATDOCDIR} \
			${OMEGATDOCDIR}/images

pre-patch:
	${INSTALL_DATA} ${FILESDIR}/OmegaT.in ${WRKSRC}/OmegaT
	for f in ${WRKSRC}/build.xml; do		\
		${TR} -d '\r' < $${f} > $${f}.new;	\
		${MV} $${f}.new $${f};			\
	done

do-build:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
		${LOCALBASE}/bin/ant jar release

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/*txt \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/*html \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/OmegaT.jar \
		${DESTDIR}${PREFIX}/${OMEGATDIR}
	cd ${WRKSRC}/dist/docs && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}
	cd ${WRKSRC}/dist/images && pax -rw -pmp * \
		${DESTDIR}${PREFIX}/${OMEGATDOCDIR}/images
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.txt \
		${DESTDIR}${PREFIX}/${OMEGATDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/dist/lib/*.jar \
		${DESTDIR}${PREFIX}/${OMEGATDIR}/lib
	${INSTALL_DATA} ${FILESDIR}/omegat.prefs \
		${DESTDIR}${PREFIX}/${OMEGATDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/OmegaT ${DESTDIR}${PREFIX}/bin

.include "../../mk/java-env.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
