# $NetBSD: Makefile,v 1.6 2025/02/02 20:31:27 schmonz Exp $
#

DISTNAME=	qmail-server-1.0.20250202
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Ingredients for typical qmail-based mail server

DEPENDS+=	dovecot-pigeonhole-[0-9]*:../../mail/dovecot2-pigeonhole
DEPENDS+=	ezmlm-idx-[0-9]*:../../mail/ezmlm-idx
DEPENDS+=	${PYPKGPREFIX}-acme-tiny-[0-9]*:../../security/py-acme-tiny
DEPENDS+=	pymsgauth-[0-9]*:../../mail/pymsgauth
DEPENDS+=	qmail-autoresponder-[0-9]*:../../mail/qmail-autoresponder
DEPENDS+=	qmail-run-[0-9]*:../../mail/qmail-run
DEPENDS+=	qtools-[0-9]*:../../mail/qtools
DEPENDS+=	queue-repair-[0-9]*:../../mail/queue-repair
DEPENDS+=	rspamd-[0-9]*:../../mail/rspamd
DEPENDS+=	vmailmgr-[0-9]*:../../mail/vmailmgr

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

.if ${INIT_SYSTEM} != "smf"
DEPENDS+=	rc.d-boot-[0-9]*:../../pkgtools/rc.d-boot
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
