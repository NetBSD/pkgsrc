# $NetBSD: Makefile,v 1.6 2004/08/22 13:47:28 schmonz Exp $
#

DISTNAME=		qmail-qfilter-1.5
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		qmail-queue multi-filter front end

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR=	qmail-qfilters
MAKE_DIRS+=		${PKG_SYSCONFDIR}

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

INSTALLATION_DIRS=	bin man man/man1 share/examples/qmail-qfilter

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail-qfilter-queue.sh	\
		> ${WRKDIR}/qmail-qfilter-queue

do-install:
	cd ${WRKSRC} && ./installer && ./instcheck
	${INSTALL_SCRIPT} ${WRKDIR}/qmail-qfilter-queue ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${PREFIX}/share/examples/qmail-qfilter;		\
	done

.include "../../mk/bsd.pkg.mk"
