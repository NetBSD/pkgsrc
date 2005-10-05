# $NetBSD: options.mk,v 1.2 2005/10/05 13:29:51 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.nmh
PKG_SUPPORTED_OPTIONS=		nmh-backup-hash

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
