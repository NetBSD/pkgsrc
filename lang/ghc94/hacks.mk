.if !defined(GHC_HACKS_MK)
GHC_HACKS_MK=	defined

### [Mon Feb  6 23:32:40 JST 2023 : pho]
### Use of timerfd on NetBSD 10 causes a kernel panic. Disable it until
### it's fixed:
### https://mail-index.netbsd.org/tech-kern/2023/02/05/msg028704.html
###
.if !empty(MACHINE_PLATFORM:MNetBSD-10.99.*-*)
PKG_HACKS+=	disable-timerfd
CONFIGURE_ENV+=	ac_cv_header_sys_timerfd_h=no
.endif

.endif	# GHC_HACKS_MK
