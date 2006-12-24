# $NetBSD: hacks.mk,v 1.1 2006/12/24 14:07:55 schwarz Exp $

.if !defined(PKG_INSTALL-INFO_HACKS_MK)
PKG_INSTALL-INFO_HACKS_MK=	#defined

### [Sat Dec 23 16:09:15 CET 2006: schwarz]
### work around gcc optimization issue (gcc bug report c/14675)
### see http://gcc.gnu.org/ml/gcc-bugs/2004-03/msg02604.html
###
.  if !empty(PKGSRC_COMPILER:Mgcc*) && !empty(CFLAGS:M-O3)
PKG_HACKS+=	suppress-Werror
BUILDLINK_TRANSFORM+=	rm:-Werror
.  endif

.endif
