# $Id: hacks.mk,v 1.1 2007/01/15 23:04:24 dmcmahill Exp $

.if !defined(FOO_TGIF_MK)
TGIF_HACKS_MK=	defined

### [Mon Jan 15 17:44:27 EST 2007 : dmcmahill]
### Sunpro cc (Sun C 5.8 2005/10/13) on SunOS-5.9/sparc
### src/arc.c
###
### cc: Fatal error in /opt/SUNWspro/prod/bin/iropt
### Status 139
### cc: iropt failed for arc.c
###
### Work around by not optimizing

.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=	optimisation
BUILDLINK_TRANSFORM+= rm:-O2
.endif

.endif  # TGIF_HACKS_MK
