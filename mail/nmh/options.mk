# $NetBSD: options.mk,v 1.1 2005/09/22 22:00:42 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nmh
PKG_SUPPORTED_OPTIONS=		nmh-backup-hash
PKG_OPTIONS_LEGACY_VARS+=	NMH_HASH_BACKUP:nmh-backup-hash

.include "../../mk/bsd.options.mk"

###
### Prepend a "#" instead of a "," to the name of a message that is
### "removed" by rmm.
###
.if !empty(PKG_OPTIONS:Mnmh-backup-hash)
post-configure: nmh-hash-backup

nmh-hash-backup:
	cd ${WRKSRC}; file=config.h;					\
	${SED} -e 's/^\(#define  *BACKUP_PREFIX\)  *.*/\1 "#"/'		\
		$$file > $$file.new;					\
	${MV} -f $$file.new $$file
.endif
