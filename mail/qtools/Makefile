# $NetBSD: Makefile,v 1.20 2020/11/19 09:35:40 schmonz Exp $
#

DISTNAME=		qtools-0.56
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.superscript.com/qtools/
COMMENT=		Utilities for filtering via .qmail

DEPENDS+=		{ezmlm>=0.53,ezmlm-idx-[0-9]*}:../../mail/ezmlm
DEPENDS+=		qmail>=1.03:../../mail/qmail

DJB_CONFIG_CMDS=	${ECHO} ${LOCALBASE:Q} > ${WRKSRC}/conf-ezmlm

SUBST_CLASSES+=		djberrno

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	cd ${FILESDIR} && for i in *.1; do \
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$i; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
