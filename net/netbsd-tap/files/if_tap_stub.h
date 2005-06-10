/*
 * fdclone() stuff
 */
#if __NetBSD_Version__ < 299001100
int	tap_fdclone(struct proc *, struct file *, int, int, struct fileops *, void *);
int	tap_fnullop_fcntl(struct file *, u_int, void *, struct proc *);
int	tap_fbadop_stat(struct file *, struct stat *, struct proc *);
#else
/* 2.99.15 is gray area.  Oh, well. */
# if __NetBSD_Version__ < 299001600
#define tap_fdclone(p,fp,fl,fd,fops,data)		fdclone(p,fp,fd,fops,data)
# else
#define tap_fdclone		fdclone
# endif
#define tap_fnullop_fcntl	fnullop_fcntl
#define tap_fbadop_stat		fbadop_stat
#endif

/*
 * hexdigits
 */
#if __NetBSD_Version__ < 399000400
extern const char tap_hexdigits[];
#else
#define tap_hexdigits hexdigits
#endif
