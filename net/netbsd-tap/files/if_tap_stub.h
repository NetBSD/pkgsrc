#if __NetBSD_Version__ < 299001100
int	tap_fdclone(struct proc *, struct file *, int, struct fileops *, void *);
int	tap_fnullop_fcntl(struct file *, u_int, void *, struct proc *);
int	tap_fbadop_stat(struct file *, struct stat *, struct proc *);
#else
#define tap_fdclone		fdclone
#define tap_fnullop_fcntl	fnullop_fcntl
#define tap_fbadop_stat		fbadop_stat
#endif
