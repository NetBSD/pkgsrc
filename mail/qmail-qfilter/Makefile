# $NetBSD: Makefile,v 1.7 2004/08/23 03:30:20 schmonz Exp $
#

DISTNAME=		qmail-qfilter-1.5
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/qmail-qfilter/
COMMENT=		qmail-queue multi-filter front end

DEPENDS+=		qmail>=1.03nb9:../../mail/qmail

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

REPLACE_PERL=		samples/block-long-dates			\
			samples/deny-filetypes				\
			samples/rename-filetypes

INSTALLATION_DIRS=	bin man man/man1 share/examples/qmail-qfilter

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man

do-install:
	cd ${WRKSRC} && ./installer && ./instcheck
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qmail-qfilter
	for i in ${REPLACE_PERL}; do					\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i}			\
			${PREFIX}/share/examples/qmail-qfilter;		\
	done

.include "../../mk/bsd.pkg.mk"
