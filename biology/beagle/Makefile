# $NetBSD: Makefile,v 1.1 2021/05/26 19:13:39 brook Exp $

PKGNAME=	beagle-5.2
CATEGORIES=	biology
MASTER_SITES=	https://faculty.washington.edu/browning/beagle/
DIST_SUBDIR=	beagle-5.2
DISTFILES+=	beagle.21Apr21.304.jar
DISTFILES+=	bref3.21Apr21.304.jar
DISTFILES+=	test.21Apr21.304.vcf.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://faculty.washington.edu/browning/beagle/
COMMENT=	Phasing genotypes and imputing ungenotyped markers
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_TOOLS+=	cut gzip tr
NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	beagle.sh bref3.sh
SUBST_VARS.prefix+=	PREFIX
SUBST_VARS.prefix+=	JAVA_BINPREFIX

EGDIR=			${PREFIX}/share/examples/beagle

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_FILES.egdir=	beagle-example.sh
SUBST_VARS.egdir=	EGDIR

INSTALLATION_DIRS+=	bin libexec/beagle share/examples/beagle

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}

post-extract:
	${CP} ${FILESDIR}/beagle.sh ${WRKSRC}
	${CP} ${FILESDIR}/beagle-example.sh ${WRKSRC}
	${CP} ${FILESDIR}/bref3.sh ${WRKSRC}
	${GZIP_CMD} -cd < ${WRKSRC}/test.21Apr21.304.vcf.gz \
	| ${CUT} -f1-190 \
	| ${TR} '/' '|' \
	| ${GZIP_CMD} > ${WRKSRC}/ref.21Apr21.304.vcf.gz
	${GZIP_CMD} -cd < ${WRKSRC}/test.21Apr21.304.vcf.gz \
	| ${CUT} -f1-9,191-200 \
	| ${GZIP_CMD} > ${WRKSRC}/target.21Apr21.304.vcf.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/beagle.sh ${DESTDIR}${PREFIX}/bin/beagle
	${INSTALL_SCRIPT} ${WRKSRC}/bref3.sh ${DESTDIR}${PREFIX}/bin/bref3
	${INSTALL_DATA} ${WRKSRC}/beagle.21Apr21.304.jar ${DESTDIR}${PREFIX}/libexec/beagle
	${INSTALL_DATA} ${WRKSRC}/bref3.21Apr21.304.jar ${DESTDIR}${PREFIX}/libexec/beagle
	${INSTALL_SCRIPT} ${WRKSRC}/beagle-example.sh ${DESTDIR}${PREFIX}/share/examples/beagle
	${INSTALL_DATA} ${WRKSRC}/ref.21Apr21.304.vcf.gz ${DESTDIR}${PREFIX}/share/examples/beagle
	${INSTALL_DATA} ${WRKSRC}/target.21Apr21.304.vcf.gz ${DESTDIR}${PREFIX}/share/examples/beagle
	${INSTALL_DATA} ${WRKSRC}/test.21Apr21.304.vcf.gz ${DESTDIR}${PREFIX}/share/examples/beagle

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
