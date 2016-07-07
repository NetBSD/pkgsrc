# $NetBSD: options.mk,v 1.3 2016/07/07 08:35:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.duplicity
PKG_SUPPORTED_OPTIONS=	duplicity-amazons3 duplicity-dropbox gnupg2
PKG_SUGGESTED_OPTIONS=	duplicity-amazons3 duplicity-dropbox

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mduplicity-amazons3)
DEPENDS+=	${PYPKGPREFIX}-boto-[0-9]*:../../net/py-boto
.endif

.if !empty(PKG_OPTIONS:Mduplicity-dropbox)
DEPENDS+=	${PYPKGPREFIX}-dropbox-[0-9]*:../../net/py-dropbox
.endif

.if !empty(PKG_OPTIONS:Mgnupg2)
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
GPGPATH=	${PREFIX}/bin/gpg2
.else
DEPENDS+=	gnupg>=1.0.0:../../security/gnupg
GPGPATH=	${PREFIX}/bin/gpg
.endif
