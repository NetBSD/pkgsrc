# $NetBSD: Makefile,v 1.12 2004/04/25 05:10:02 snj Exp $
#

DISTNAME=	portsentry-1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sentrytools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sentrytools/
COMMENT=	Detects and respond to port scans against a target host in real-time

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
WRKSRC=		${WRKDIR}/portsentry_beta

ALL_TARGET=	${LOWER_OPSYS}

EGDIR=		${PREFIX}/share/examples/portsentry
CONF_FILES=	${EGDIR}/portsentry.conf ${PKG_SYSCONFDIR}/portsentry.conf
CONF_FILES+=	${EGDIR}/portsentry.ignore ${PKG_SYSCONFDIR}/portsentry.ignore

post-patch:
	@cd ${WRKSRC};							\
	case ${OPSYS} in						\
	NetBSD)	netbsd=""; solaris="#" ;;				\
	SunOS)	netbsd="#"; solaris="" ;;				\
	esac;								\
	for f in portsentry.conf portsentry_config.h; do		\
		${MV} $$f $$f.prefix;					\
		${SED} -e 's|@PREFIX@|${PREFIX}|g' 			\
			-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'	\
			-e 's|@netbsd@|'$$netbsd'|g'			\
			-e 's|@solaris@|'$$solaris'|g'			\
						$$f.prefix > $$f;	\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/portsentry
	${INSTALL_DATA} ${WRKSRC}/README.install ${PREFIX}/share/doc/portsentry
	${INSTALL_DATA} ${WRKSRC}/README.methods ${PREFIX}/share/doc/portsentry

.include "../../mk/bsd.pkg.mk"
