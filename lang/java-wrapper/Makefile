# $NetBSD: Makefile,v 1.3 2004/10/05 22:03:42 tv Exp $
#

DISTNAME=	java-wrapper-1.2
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Runs different Java implementations transparently

NO_BUILDLINK=		YES
NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
USE_PKGINSTALL=		YES
WRKSRC=			${WRKDIR}

EGDIR=			${PREFIX}/share/examples/java-wrapper
CONF_FILES=		${EGDIR}/java-wrapper.conf \
			${PKG_SYSCONFDIR}/java-wrapper.conf

SUBST_CLASSES+=		build
SUBST_STAGE.build=	do-build
SUBST_MESSAGE.build=	Setting up paths.
SUBST_FILES.build=	java-wrapper.1
SUBST_FILES.build+=	java-wrapper.conf
SUBST_FILES.build+=	java-wrapper.sh
SUBST_SED.build=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.build+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.build+=	-e 's|@SH@|${SH}|g'
SUBST_SED.build+=	-e 's|@TR@|${TR}|g'

INSTALLATION_DIRS=	bin man/man1

do-extract:
	${CP} ${FILESDIR}/java-wrapper.1 ${WRKSRC}
	${CP} ${FILESDIR}/java-wrapper.conf ${WRKSRC}
	${CP} ${FILESDIR}/java-wrapper.sh ${WRKSRC}

do-build:
	@${DO_NADA}

# Not all implemetations supply all of the following programs, but these
# comprise the majority of useful tools available with most JVMs:
do-install:
.for f in appletviewer apt extcheck idlj jar jarsigner java javac javadoc \
	  javah javakey javap javaws jdb keytool policytool rmic rmid \
	  rmiregistry serialver servertool tnameserv
	${INSTALL_SCRIPT} ${WRKSRC}/java-wrapper.sh ${PREFIX}/bin/${f}
.endfor
.undef f
	${INSTALL_DATA} ${WRKSRC}/java-wrapper.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/java-wrapper.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
