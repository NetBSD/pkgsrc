# $NetBSD: Makefile,v 1.22 2026/02/01 09:05:11 wiz Exp $

DISTNAME=		qtools-0.56
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://www.superscript.com/qtools/
COMMENT=		Utilities for filtering via .qmail

DEPENDS+=		{ezmlm>=0.53,ezmlm-idx-[0-9]*}:../../mail/ezmlm
DEPENDS+=		qmail>=1.03:../../mail/qmail

FORCE_C_STD=		c89

DJB_CONFIG_CMDS=	${ECHO} ${PREFIX:Q} > ${WRKSRC}/conf-ezmlm;
DJB_ERRNO_FIXUP=	error.h

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-install:
	cd ${FILESDIR} && for i in *.1; do \
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/$$i; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
