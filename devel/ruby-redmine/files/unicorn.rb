working_directory "@PREFIX@/@RM_DIR@/app"
pid "@PREFIX@/@RM_DIR@/unicorn.pid"
stderr_path "@PREFIX@/@RM_DIR@/unicorn.log"
stdout_path "@PREFIX@/@RM_DIR@/unicorn.log"

worker_processes 3
listen "@PREFIX@/@RM_DIR@/unicorn.redmine.sock"
timeout 60
