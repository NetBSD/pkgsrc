working_directory "@PREFIX@/share/redmine/app"
pid "@PREFIX@/share/redmine/unicorn.pid"
stderr_path "@PREFIX@/share/redmine/unicorn.log"
stdout_path "@PREFIX@/share/redmine/unicorn.log"
 
worker_processes 3
listen "@PREFIX@/share/redmine/unicorn.redmine.sock"
timeout 60
